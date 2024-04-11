const
  base=1000000007;

var
  t,x,px,res,kg,i,n,st:longint;
  prx,drx:array[0..500500]of longint;
  
  procedure fs(x:longint;var px,dx:longint);
    var
      tmp:longint;
      
    begin
      if (prx[x]<>x)then begin
        tmp:=drx[x];
        fs(prx[x],px,dx);
        prx[x]:=px;
        dx:=(dx+tmp)mod base;
        drx[x]:=dx;
        exit;
      end;
      px:=x;dx:=0;
    end;

begin
  read(n);
  res:=0;
  for i:=1 to n do prx[i]:=i;
  for i:=1 to n do drx[i]:=0;
  for i:=1 to n do begin
    read(kg);
    while (kg>0)do begin
      dec(kg);
      read(x,t);
      if (t<0)then inc(t,base);
      fs(x,px,st);
      st:=(st+t)mod base;
      res:=(res+st)mod base;
      prx[px]:=i;
      drx[px]:=st;
    end;
  end;
  writeln(res);
end.