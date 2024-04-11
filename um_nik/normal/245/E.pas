var i,n,k,m,p,q:integer;
s:string;
begin
readln(s);
n:=length(s);
k:=0;
m:=0;
p:=0;
q:=0;
for i:=1 to n do
  begin
  if s[i]='-' then k:=k-1 else k:=k+1;
  if (k>0) and (p<k) then p:=k;
  if (k<0) and (q>k) then q:=k;
  end;
m:=p-q;
writeln(m);
end.