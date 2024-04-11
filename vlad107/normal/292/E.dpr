type
  TTree=record
    all,l,r:longint;
  end;

var
  ii,n,m,i,qt:longint;
  x,y,k,a,b:array[0..500500]of longint;
  tr:array[0..500500]of TTree;
  
  procedure build(x,l,r:longint);
    begin
      tr[x].l:=l;
      tr[x].r:=r;
      tr[x].all:=0;
      if (l<r)then begin
        build(x+x,l,(l+r)shr 1);
        build(x+x+1,(l+r)shr 1+1,r);
      end;
    end;
    
  procedure push(x:longint);
    begin
      if (tr[x].all=0)then exit;
      if (tr[x].l<>tr[x].r)then begin
        tr[x+x].all:=tr[x].all;
        tr[x+x+1].all:=tr[x].all;
        tr[x].all:=0;
      end;
    end;
    
  procedure modify(x,l,r,val:longint);
    begin
      if (r<tr[x].l)then exit;
      if (l>tr[x].r)then exit;
      if (l<=tr[x].l)and(r>=tr[x].r)then begin
        tr[x].all:=val;
        push(x);
        exit;
      end;
      push(x);
      modify(x+x,l,r,val);
      modify(x+x+1,l,r,val);
    end;

begin
//  assign(input,'input.txt');reset(input);
  read(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  build(1,1,n);
  for i:=1 to m do begin
    read(qt);
    if (qt=1)then begin
      read(x[i],y[i],k[i]);
      modify(1,y[i],y[i]+k[i]-1,i);
    end else begin
      read(x[i]);
      ii:=1;
      while (tr[ii].l<>tr[ii].r)do begin
        push(ii);
        if (x[i]<=tr[ii+ii].r)then ii:=ii+ii else ii:=ii+ii+1;
      end;
      push(ii);
      ii:=tr[ii].all;
      if (ii=0)then writeln(b[x[i]])else writeln(a[x[i]-y[ii]+x[ii]]);
    end;
  end;
end.