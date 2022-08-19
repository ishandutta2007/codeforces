var n,i,k,t:integer;
a,b,c,d,e:array [1..300000] of int64;

procedure f(x,y:integer);
var p,q:integer;
begin
if y mod 2=1 then
  begin
  q:=x+a[x];
  if (q<=0) or (q>n) then
    begin
    b[x]:=a[x];
    d[x]:=1;
    exit;
    end;
  if (q=1) or (y>3*n) then
    begin
    b[x]:=-1;
    d[x]:=1;
    exit;
    end;
  if (e[q]=1) then
    begin
    if c[q]=-1 then b[x]:=-1 else b[x]:=a[x]+c[q];
    d[x]:=1;
    exit;
    end;
  f(q,y+1);
  if c[q]=-1 then b[x]:=-1 else b[x]:=a[x]+c[q];
  d[x]:=1;
  end else
  begin
  q:=x-a[x];
  if (q<=0) or (q>n) then
    begin
    c[x]:=a[x];
    e[x]:=1;
    exit;
    end;
  if (q=1) or (y>3*n) then
    begin
    c[x]:=-1;
    e[x]:=1;
    exit;
    end;
  if (d[q]=1) then
    begin
    if b[q]=-1 then c[x]:=-1 else c[x]:=a[x]+b[q];
    e[x]:=1;
    exit;
    end;
  f(q,y+1);
  if b[q]=-1 then c[x]:=-1 else c[x]:=a[x]+b[q];
  e[x]:=1;
  end;
end;

begin
readln(n);
for i:=2 to n do read(a[i]);
for i:=2 to n do
  begin
  b[i]:=0;
  c[i]:=0;
  d[i]:=0;
  e[i]:=0;
  end;
for i:=2 to n do
  begin
  if d[i]=0 then
    begin
    f(i,1);
    end;
  if e[i]=0 then
    begin
    f(i,2);
    end;
  end;
//for i:=2 to n do writeln(b[i],' ',c[i],' ',d[i],' ',e[i]);
for i:=1 to n-1 do
  begin
  if c[i+1]=-1 then writeln(-1) else writeln(c[i+1]+i);
  end;
end.