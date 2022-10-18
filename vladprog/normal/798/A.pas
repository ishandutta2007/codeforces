var
  s:string;
  i,k:longint;

begin
  readln(s);
  k:=0;
  for i:=1 to length(s) do
    if s[i]<>s[length(s)+1-i]
      then inc(k);
  if (k=2)or((k<2)and odd(length(s)))
    then writeln('YES')
    else writeln('NO')
end.