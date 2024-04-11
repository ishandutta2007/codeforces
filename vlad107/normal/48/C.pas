const
  INF=1000000000;

var
  r1,r2,n,i:longint;
  x,k,ss,ff:extended;
  a:array[0..1000000] of longint;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  ss:=10*a[1];
  ff:=ss+10-0.0000001;
  for i:=2 to n do begin
    k:=10*a[i]/i;
    if (k>ss)then ss:=k;
    k:=10*(a[i]+1)/i-0.0000001;
    if (k<ff)then ff:=k;
  end;
  x:=0;
  a[0]:=0;
  for i:=1 to n do begin
    x:=x+ss;
    x:=x-(a[i]-a[i-1])*10;
  end;
  x:=x+ss;
  r1:=trunc(x)div 10;
  x:=0;
  for i:=1 to n do begin
    x:=x+ff;
    x:=x-(a[i]-a[i-1])*10;
  end;
  x:=x+ff;
  r2:=trunc(x)div 10;
  if (r1<>r2)or(r1=0)
    then writeln('not unique')
    else begin
      writeln('unique');
      writeln(r1+a[n]);
    end;
end.