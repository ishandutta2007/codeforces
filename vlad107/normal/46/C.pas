//type
//  ansistring=string;

var
  n,i,j,r1,r2,res:longint;
  t,s,p:ansistring;

begin
  readln(n);
  readln(s);
  s:=s+s;
  p:='';
  t:='';
  for i:=1 to n do
    if (s[i]='T')then p:=p+s[i] else t:=t+s[i];
  for i:=1 to n do
    if (s[i]='H')then p:=p+s[i] else t:=t+s[i];
  res:=n;
  for i:=1 to n do begin
    r1:=0;r2:=0;
    for j:=i to i+n-1 do begin
      if (s[j]<>t[j-i+1])then inc(r1);
      if (s[j]<>p[j-i+1])then inc(r2);
    end;
    if (r1<res)then res:=r1;
    if (r2<res)then res:=r2;
  end;
  writeln(res div 2);
end.