var
  i:longint;
  l,s,r,p:array[1..4]of longint;

begin
  for i:=1 to 4 do
    read(l[i],s[i],r[i],p[i]);
  if ((p[1]and(l[2] or s[3] or r[4] or l[1] or s[1] or r[1]))=1)or
     ((p[2]and(r[1] or l[3] or s[4] or l[2] or s[2] or r[2]))=1)or
     ((p[3]and(s[1] or r[2] or l[4] or l[3] or s[3] or r[3]))=1)or
     ((p[4]and(l[1] or s[2] or r[3] or l[4] or s[4] or r[4]))=1)
    then writeln('YES')
    else writeln('NO')
end.