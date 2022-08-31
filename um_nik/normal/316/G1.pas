var s0,s,t:string;
m,x,y,n,i,j,k,h,ans:integer;
p:array [1..10] of string;
c:char;
f,g:array [1..10] of integer;
z:array [0..500] of integer;

procedure zfunc(s:string);
var n,l,r,i:integer;
begin
n:=length(s);
z[1]:=0;
l:=1;
r:=1;
for i:=2 to n do
  begin
  //writeln(i);
  z[i]:=0;
  if i<=r then
    begin
    z[i]:=z[i-l+1];
    if z[i]>r-i+1 then z[i]:=r-i+1;
    end;
  //writeln(i,' ',z[i]);
  while (i+z[i]<=n) do
    begin
    if s[i+z[i]]=s[z[i]+1] then z[i]+=1 else break;
    end;
  if i+z[i]-1>r then
    begin
    l:=i;
    r:=i+z[i]-1;
    end;
  end;
end;

begin

{zfunc('a#aa');
for i:=1 to 4 do write(z[i],' ');
}

readln(s0);
n:=length(s0);
readln(m);
for i:=1 to m do
  begin
  p[i]:='';
  while true do
    begin
    read(c);
    if c=' ' then break;
    p[i]+=c;
    end;
  readln(f[i],g[i]);
  end;
ans:=0;
for i:=1 to n do
  for j:=i+1 to n+1 do
    begin
    t:=copy(s0,i,j-i);
    y:=1;
    for h:=1 to i-1 do
      begin
      if t=copy(s0,h,j-i) then
        begin
        y:=0;
        break;
        end;
      end;
    if y=0 then continue;
    for k:=1 to m do
      begin
      s:=t+'#'+p[k];
      zfunc(s);
      x:=0;
      for h:=2 to length(s) do
        if z[h]=j-i then x+=1;
      {writeln(t,' ',s);
      for h:=1 to length(s) do write(z[i],' ');
      writeln();
      writeln(x);}
      if (x>=f[k]) and (x<=g[k]) then else
        begin
        y:=0;
        break;
        end;
      end;
    if y=1 then ans+=1;
    end;
writeln(ans);
end.