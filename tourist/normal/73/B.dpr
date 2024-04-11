{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
{$M 30000000}
var
  b,pts: array [0..100010] of longint;
  nam: array [0..100010] of string;
  my: string;
  low,high,m,pl,cur,tmp,me,n,i: longint;
  ch: char;

procedure SortB(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=b[l+random(r-l+1)];
  repeat
    while b[i] > x do inc(i);
    while x > b[j] do dec(j);
    if i <= j then
    begin
      tmp:=b[i]; b[i]:=b[j]; b[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then SortB(l,j);
  if i < r then SortB(i,r);
end;

procedure SortP(l,r:longint);
var
  i,j,x,tmp: longint;
  y,tt: string;
begin
  i:=l; j:=r;
  x:=pts[l+random(r-l+1)];
  y:=nam[l+random(r-l+1)];
  repeat
    while (pts[i] > x) or (pts[i] = x) and (nam[i] < y) do inc(i);
    while (x > pts[j]) or (x = pts[j]) and (y < nam[j]) do dec(j);
    if i <= j then
    begin
      tmp:=pts[i]; pts[i]:=pts[j]; pts[j]:=tmp;
      tt:=nam[i]; nam[i]:=nam[j]; nam[j]:=tt;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then SortP(l,j);
  if i < r then SortP(i,r);
end;

begin
  randseed:=8753;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do
  begin
    read(ch);
    while not (ch in ['a'..'z']) do read(ch);
    nam[i]:='';
    while ch in ['a'..'z'] do
    begin
      nam[i]:=nam[i]+ch;
      read(ch);
    end;
    read(pts[i]);
  end;
  read(m);
  for i:=1 to m do read(b[i]);
  if m > 0 then SortB(1,m);
  for i:=m+1 to n do b[i]:=0;
  read(ch);
  while not (ch in ['a'..'z']) do read(ch);
  my:='';
  while ch in ['a'..'z'] do
  begin
    my:=my+ch;
    read(ch);
  end;
  me:=0;
  for i:=1 to n do
    if nam[i] = my then
    begin
      me:=i;
      break;
    end;
  tmp:=pts[1]; pts[1]:=pts[me]; pts[me]:=tmp;
  my:=nam[1]; nam[1]:=nam[me]; nam[me]:=my;
  if n > 1 then SortP(2,n);
  pl:=1; cur:=1;
  for i:=n downto 2 do
    if (pts[i]+b[pl] > pts[1]+b[n]) or
       (pts[i]+b[pl] = pts[1]+b[n]) and (nam[i] < nam[1]) then
    begin
      inc(pl);
      inc(cur);
    end;
  low:=cur;
  pl:=n; cur:=n;
  for i:=2 to n do
    if (pts[i]+b[pl] < pts[1]+b[1]) or
       (pts[i]+b[pl] = pts[1]+b[1]) and (nam[i] > nam[1]) then
    begin
      dec(pl);
      dec(cur);
    end;
  high:=cur;
  writeln(high,' ',low);
  close(input);
  close(output);
end.