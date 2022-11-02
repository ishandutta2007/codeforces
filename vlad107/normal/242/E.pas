{$r-,q-,s-,i-,o+}
type
  ttree=record
    l,r,add:longint;
    u:array[0..20]of longint;
  end;
var
  i,n,q,tt,l,r,x:longint;
  a:array[0..500500]of longint;
  tr:array[0..500500]of ttree;
  function min(x,y:longint):longint;begin if(x<y)then min:=x else min:=y;end;
  function max(x,y:longint):longint;begin if(x>y)then max:=x else max:=y;end;
  procedure build(x,l,r:longint);
    var
      i:longint;
    begin
      tr[x].l:=l;tr[x].r:=r;tr[x].add:=0;
      if (l<r)then begin
        build(x+x,l,(l+r)shr 1);
        build(x+x+1,((l+r)shr 1)+1,r);
        for i:=0 to 20 do tr[x].u[i]:=tr[x+x].u[i]+tr[x+x+1].u[i];
      end else for i:=0 to 20 do tr[x].u[i]:=ord(a[l] and (1 shl i)<>0);
    end;
  procedure upd(x:longint);inline;
    var
      i:longint;
    begin
      if (tr[x].add=0)then exit;
      for i:=0 to 20 do 
        if (tr[x].add and (1 shl i)<>0)then tr[x].u[i]:=tr[x].r-tr[x].l+1-tr[x].u[i];
      if (tr[x].l<>tr[x].r)then begin
        tr[x+x].add:=tr[x+x].add xor tr[x].add;
        tr[x+x+1].add:=tr[x+x+1].add xor tr[x].add;
      end;
      tr[x].add:=0;
    end;
  function findsum(x,l,r:longint):int64;
    var
      res:int64;
      i:longint;
    begin
      upd(x);
      if (tr[x].l=l)and(tr[x].r=r)then begin
        res:=0;for i:=0 to 20 do res:=res+int64(tr[x].u[i])*(1 shl i);
        findsum:=res;exit;
      end else begin
        res:=0;
        if (l<=tr[x+x].r)then res:=res+findsum(x+x,l,min(r,tr[x+x].r));
        if (r>=tr[x+x+1].l)then res:=res+findsum(x+x+1,max(l,tr[x+x+1].l),r);
        findsum:=res;
      end;
    end;
  procedure modify(x,l,r,val:longint);
    begin
      upd(x);
      if (tr[x].l=l)and(tr[x].r=r)then begin 
        tr[x].add:=tr[x].add xor val;
        upd(x);
        exit;
      end else begin
        if (l<=tr[x+x].r)then modify(x+x,l,min(r,tr[x+x].r),val) else upd(x+x);
        if (r>=tr[x+x+1].l)then modify(x+x+1,max(l,tr[x+x+1].l),r,val) else upd(x+x+1);
        for i:=0 to 20 do tr[x].u[i]:=tr[x+x].u[i]+tr[x+x+1].u[i];
      end;
    end;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  build(1,1,n);
  read(tt);
  while (tt>0)do begin
    dec(tt);
    read(q);
    if (q=1)then begin
      read(l,r);
      writeln(findsum(1,l,r));
    end else begin
      read(l,r,x);
      modify(1,l,r,x);
    end;
  end;
end.