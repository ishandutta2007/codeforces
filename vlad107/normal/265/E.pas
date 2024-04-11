{$r-,q-,s-,i-,o+}
const
  inf:int64=1000000000000000000;

var
  tmax,cr1,cr2,ct,max1,max2:int64;
  nom1,nom2,a,b,n,tt,i:longint;
  c,v:array[0..500500]of longint;
  g:array[0..500500]of int64;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,tt);
  for i:=1 to n do read(v[i]);
  for i:=1 to n do read(c[i]);
  while (tt>0)do begin
    dec(tt);
    read(a,b);
    for i:=1 to n do g[i]:=-inf;
    max1:=-inf;max2:=-inf;
    nom1:=1;nom2:=2;
    for i:=1 to n do begin
      ct:=g[c[i]];
      if (ct<>-inf)
        then cr1:=int64(v[i])*a+ct
        else cr1:=ct;
      tmax:=max1;
      if (nom1=c[i])then tmax:=max2;
      if (tmax<>-inf)
        then begin
          cr2:=int64(v[i])*b+tmax;
          if (cr2>cr1)Then cr1:=cr2;
        end;
      if (cr1>ct)then ct:=cr1;
      if (int64(v[i])*b>ct)then ct:=int64(v[i])*b;
      g[c[i]]:=ct;
      if (ct>=max1)then begin
        if (nom1=c[i])
          then max1:=ct
          else begin
            max2:=max1;
            nom2:=nom1;
            max1:=ct;
            nom1:=c[i];
          end;
      end else
      if (ct>=max2)then begin
        max2:=ct;
        nom2:=c[i];
      end;
    end;
    cr1:=0;
    for i:=1 to n do 
      if (g[i]>cr1)then cr1:=g[i];
    writeln(cr1);
  end;
end.