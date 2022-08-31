var i,n,t,q,p:integer;
s:string;
begin
readln(s);
n:=length(s);
if s[1]='h' then q:=1 else q:=2;
for i:=n-1 downto 1 do
  begin
  if (s[i]='r') and (s[i+1]='u') then 
    begin
    t:=i;
    if i<n-1 then p:=1 else p:=0;
    break;
    end;
  end;
if q=1 then
  begin
  write('http://');
  write(copy(s,5,t-5));
  write('.ru');
  if p=1 then
    begin
    write('/');
    write(copy(s,t+2,n-t-1));
    end;
  end else
  begin
  write('ftp://');
  write(copy(s,4,t-4));
  write('.ru');
  if p=1 then
    begin
    write('/');
    write(copy(s,t+2,n-t-1));
    end;
  end;
end.