{$R-,S-,Q-,I-,O+}
var
  s,t: ansistring;
  n,m,i,j,lg,rg: longint;
  ok: boolean;
  a: array ['a'..'z',0..200010] of longint;
  c: char;
  left,right: array [0..200010] of longint;

function exists(lg,rg:longint;ch:char):boolean;
begin
  if a[ch,rg]-a[ch,lg-1] > 0 then exists:=True
  else exists:=False;
end;

begin  
  readln(s);
  readln(t);
  n:=length(s);
  m:=length(t);
  j:=1;
  for i:=1 to n do
  begin
    left[i]:=j-1;
    if (j <= m) and (s[i] = t[j]) then inc(j);
  end;
  j:=m;
  for i:=n downto 1 do
  begin
    right[i]:=m-j;
    if (j > 0) and (s[i] = t[j]) then dec(j);
  end;
  fillchar(a,sizeof(a),0);
  for c:='a' to 'z' do
    for i:=1 to m do
    begin
      a[c,i]:=a[c,i-1];
      if t[i] = c then inc(a[c,i]);
    end;
  ok:=True;
  for i:=1 to n do
  begin
    lg:=m-right[i];
    rg:=left[i]+1;
    if lg < 1 then lg:=1;
    if rg > m then rg:=m;
    if lg > rg then ok:=False else
    if not exists(lg,rg,s[i]) then ok:=False;
    if not ok then break;
  end;
  if ok then writeln('Yes')
  else writeln('No');
end.