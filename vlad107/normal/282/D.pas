uses
  math;

const
  Fir='BitLGM';
  Sec='BitAryo';

var
  f:array[0..333,0..333]of longint;
  n,m,k,i,j:longint;

begin
  read(n);
  if (n=1)then begin
    read(n);
    if (n>0)then writeln(Fir)else writeln(Sec);
  end else 
  if (n=3)then begin
    read(n,m,k);
    n:=n xor m xor k;
    if (n>0)then writeln(Fir)else writeln(Sec);
  end else begin
    read(n,m);
    for i:=0 to n do
      for j:=0 to m do 
        for k:=1 to max(i,j)do
          if ((k<=i)and(f[i-k][j]=0))or
              ((k<=j)and(f[i][j-k]=0))or
              ((k<=i)and(k<=j)and(f[i-k][j-k]=0))
                then begin f[i][j]:=1;break; end;              
    if (f[n][m]=1)then writeln(Fir)else writeln(Sec);
  end;
end.