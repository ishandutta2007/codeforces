{$r+,q+,s+,i+,o-}
var
  t,a:array[0..1005000]of longint;
  used:array[0..1000500]of boolean;
  s,sum:int64;
  n,i,j:longint;

begin
  read(n);
  s:=int64(n)*(N+1);
  writeln(s);
  for i:=0 to 20 do t[i]:=(1 shl i)-1;
  for i:=n downto 0 do begin
    j:=20;
    while (t[j]xor i>n)or(t[j]>s)or(used[t[j] xor i])do dec(j);
    used[t[j] xor i]:=true;
    s:=s-t[j];
    a[i]:=t[j] xor i;
  end;
  for i:=0 to n do write(a[i],' ');
  writeln;
end.