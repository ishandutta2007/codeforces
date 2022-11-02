{$r-,q-,s-,i-,o+}
uses
  math;

type
  TTree=record
    inv,k4,k7,max47,max74,l,r:longint;
  end;

var
  a:array[0..4000500]of longint;
  tt,l,r,n,i:longint;
  ch:char;
  tr:array[0..4000500]of TTree;

  procedure swap(var a,b:longint);
    var
      tmp:longint;

    begin
      tmp:=a;a:=b;b:=tmp;
    end;

  procedure push(x:longint);
    begin
      if (tr[x].inv=1)then begin
        swap(tr[x].k4,tr[x].k7);
        swap(tr[x].max47,tr[x].max74);
        tr[x].inv:=0;
        if (tr[x].l=tr[x].r)then exit;
        tr[x+x].inv:=1-tr[x+x].inv;
        tr[x+x+1].inv:=1-tr[x+x+1].inv;
      end;
    end;

  procedure update(x:longint);
    begin
      push(x+x);
      push(x+x+1);
      tr[x].k4:=tr[x+x].k4+tr[x+x+1].k4;
      tr[x].k7:=tr[x+x+1].k7+tr[x+x].k7;

      tr[x].max47:=tr[x+x].k4+tr[x+x+1].max47;
      if (tr[x+x].max47+tr[x+x+1].k7>tr[x].max47)then tr[x].max47:=tr[x+x].max47+tr[x+x+1].k7;

      tr[x].max74:=tr[x+x].k7+tr[x+x+1].max74;
      if (tr[x+x].max74+tr[x+x+1].k4>tr[x].max74)then tr[x].max74:=tr[x+x].max74+tr[x+x+1].k4;
    end;

  procedure build(x,l,r:longint);
    begin
      tr[x].l:=l;tr[x].r:=r;
      tr[x].inv:=0;
      if (l<r)then begin
        build(x+x,l,(l+r)shr 1);
        build(x+x+1,(l+r)shr 1+1,r);
        update(x);
        exit;
      end;
      tr[x].max47:=1;
      tr[x].max74:=1;
      tr[x].k4:=ord(a[l]=4);
      tr[x].k7:=ord(a[l]=7);
    end;

  procedure invert(x,l,r:longint);
    begin
      if (tr[x].l=l)and(tr[x].r=r)then begin
        tr[x].inv:=1-tr[x].inv;
        push(x);
        exit;
      end;
      push(x);
      if (l<=tr[x+x].r)then invert(x+x,l,min(tr[x+x].r,r));
      if (r>=tr[x+x+1].l)then invert(x+x+1,max(l,tr[x+x+1].l),r);
      update(x);
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  readln(n,tt);
  for i:=1 to n do begin
    read(ch);
    if (ch='4')then a[i]:=4 else a[i]:=7;
  end;
  readln;
  build(1,1,n);
  while (tt>0)do begin
    dec(tt);
    read(ch);
    if (ch='s')then begin
      read(ch,ch,ch,ch,ch);
      readln(l,r);
      invert(1,l,r);
    end else begin
      readln;
      writeln(tr[1].max47);
    end;
  end;
  close(output);close(input);
end.