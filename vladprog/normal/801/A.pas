var
  s:string;
  n,i,k:longint;
  ok:boolean;

begin
  readln(s);
  n:=length(s);
  k:=0;
  for i:=1 to n-1 do
    if (s[i]='V')and(s[i+1]='K')
      then inc(k);
  if (n>1)and(((s[1]='K')and(s[2]='K'))or((s[n]='V')and(s[n-1]='V')))
    then ok:=true
    else ok:=false;
  for i:=2 to n-1 do
    if (s[i-1]=s[i])and(s[i]=s[i+1])
      then ok:=true;
  if ok
    then writeln(k+1)
    else writeln(k)
end.