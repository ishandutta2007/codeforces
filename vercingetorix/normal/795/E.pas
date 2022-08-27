Uses math;
var cur,m,t,u,i,d10,dig,ans:longint;
s:string;

begin

readln(s);
readln(m);
d10:=1;
cur:=0;
t:=length(s);
for i:=1 to t do
begin
dig:=ord(s[t+1-i])-48;
cur:=(cur + dig*d10) mod m;
d10:=(d10*10) mod m;
end;
ans:=cur;
for i:=1 to t-1 do
begin
dig:=ord(s[i])-48;
cur:=(10*cur + dig*(m-d10)) mod m;
cur:=(cur+dig) mod m;
dig:=ord(s[i+1])-48;
if (dig <> 0) then
    ans := Min(ans,cur);
end;
writeln(ans);

end.