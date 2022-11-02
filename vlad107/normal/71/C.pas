{$r-,q-,s-,i-,o+}
var
  n,i,j:longint;
  a:array[0..100500]of longint;
  procedure solve(p:longint);
    var
      i,j:longint;
    begin
      for i:=1 to p do begin
        j:=i;
        while (j<=n)and(a[j]=1)do inc(j,p);
        if (j>n)then begin
          writeln('YES');
          halt(0);
        end;
      end;
    end;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=3 to n do 
    if (n mod i=0)then solve(n div i);
  writeln('NO');
end.