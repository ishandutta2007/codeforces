var n,ans,i,t:integer;
s:string;
begin
readln(s);
s:='000'+s;
n:=length(s);
i:=n;
while s[i]='0' do i-=1;
ans:=0;
while i>2 do
  begin
  ans+=1;
  if s[i-1]='0' then t:=0 else t:=1;
  i-=1;
  while ((t=0) and (s[i]='0')) or ((t=1) and (s[i]='1')) do
    begin
    if i=2 then break;
    i-=1;
    end;
  //writeln(i+1,' ',ans);
  end;
writeln(ans);
end.