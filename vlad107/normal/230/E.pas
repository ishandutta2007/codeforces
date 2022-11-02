{$r-,q-,s-,i-,o+}
var
  cr,ans:int64;
  n,m,i,x,y:longint;
  deg:array[0..2000500]of longint;

begin
  read(n,m);
  fillchaR(deg,sizeof(deg),$0);
  for i:=1 to m do begin
    read(x,y);
    inc(deg[x]);
    inc(deg[y]);
  end;
  ans:=0;
  for i:=1 to n do ans:=ans+int64(deg[i])*(n-deg[i]-1);
  cr:=int64(n)*(n-1)*(n-2)div 6;
  ans:=ans div 2;
  writeln(cr-ans);
end.