var n,k,i,j,ans:integer;
a:array [1..100100] of integer;
b:array [0..31] of integer;

begin
readln(n);
for i:=1 to n do read(a[i]);
b[0]:=1;
for i:=1 to 30 do b[i]:=2*b[i-1];
for k:=30 downto 0 do
  begin
  ans:=-1;
  for i:=1 to n do
    begin
    if a[i] and b[k]>0 then
      begin
      if ans=-1 then ans:=a[i] else ans:=ans and a[i];
      end;
    end;
  if ans mod b[k]=0 then
    begin
    ans:=0;
    for i:=1 to n do
      begin
      if a[i] and b[k]>0 then ans+=1;
      end;
    writeln(ans);
    for i:=1 to n do
      begin
      if a[i] and b[k]>0 then write(a[i],' ');
      end;
    halt;
    end;
  end;
end.