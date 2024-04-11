var ans,n,x,y:int64;
pr:array [1..6000000] of boolean;
i,j,k,p,t:integer;
a:array [1..100] of integer;
b:array [0..5000100] of boolean;

function bs(x,y:int64):int64;
begin
if y<3 then
  begin
  if y=1 then bs:=x else bs:=(x*x) mod (n+1);
  end else
  begin
  if y mod 2=0 then bs:=bs(bs(x,y div 2),2) else bs:=(bs(bs(x,y div 2),2)*x) mod (n+1);
  end;
end;

function isRoot(x:int64):boolean;
var i:integer;
begin
for i:=1 to k do
  begin
  if bs(x,a[i])=1 then
    begin
    isRoot:=false;
    exit;
    end;
  end;
isRoot:=true;
end;


begin
readln(n,x);
if n=1 then
  begin
  if x>2 then writeln(x-1) else writeln(-1);
  halt;
  end;
if n=2 then
  begin
  x-=1;
  while (x mod 3<>2) and (x>0) do x-=1;
  if x=0 then writeln(-1) else writeln(x);
  halt;
  end;
for i:=1 to 6000000 do pr[i]:=true;
pr[1]:=false;
for i:=2 to 6000 do
  begin
  if pr[i] then
    begin
    j:=i;
    while i*j<=6000000 do
      begin
      pr[i*j]:=false;
      j+=1;
      end;
    end;
  end;
if pr[n+1] then
  begin
  k:=0;
  for i:=2 to n do
    begin
    if (n mod i=0) and (pr[i]) then
      begin
      k+=1;
      a[k]:=n div i;
      end;
    end;
  
  while x>0 do
    begin
    x-=1;
    if x mod (n+1)=0 then continue;
    y:=x mod (n+1);
    if isRoot(y) then
      begin
      writeln(x);
      break;
      end;
    end;
  if x=0 then writeln(-1);
  end else writeln(-1);
end.