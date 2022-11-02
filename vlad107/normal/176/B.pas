const
  base=1000000007;

var
  f:array[0..500500,1..2]of longint;
  s,p,q:ansistring;
  n,i,k,ans:longint;

begin
  readln(s);
  readln(p);
  readln(k);
  n:=length(s);
  f[0][1]:=1;
  f[0][2]:=0;
  for i:=1 to k do begin
    f[i][1]:=int64(f[i-1][2])*(n-1)mod base;
    f[i][2]:=int64(f[i-1][2])*(n-2)mod base;
    f[i][2]:=(f[i][2]+f[i-1][1])mod base;
  end;
  if (s=p)then ans:=f[k][1] else ans:=0;
  q:=s;
  for i:=2 to length(s)do begin
    delete(q,1,1);
    q:=q+s[i-1];
    if (q=p)then ans:=(ans+f[k][2])mod base;
  end;
  writeln(ans);
end.