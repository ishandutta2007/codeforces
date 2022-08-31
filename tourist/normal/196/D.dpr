{$R-,S-,Q-,I-,O+}
const co: int64 = 129581259982959;
var
  pw,h,hr: array [0..400010] of int64;
  d,bad,i,n: longint;
  ok: boolean;
  c: char;
  s: ansistring;

function pal(a,b:longint):boolean;
var
  direct,reverse: int64;
begin
  direct:=(h[b]-h[a-1]*pw[b-a+1])*pw[a-1];
  reverse:=hr[b]-hr[a-1];
  pal:=direct = reverse;
end;

begin
  readln(d);
  readln(s);
  n:=length(s);
  pw[0]:=1;
  for i:=1 to n do pw[i]:=pw[i-1]*co;
  h[1]:=0; hr[1]:=0;
  bad:=n;
  for i:=1 to n do
  begin
    h[i]:=h[i-1]*co+Ord(s[i]);
    hr[i]:=hr[i-1]+pw[i-1]*Ord(s[i]);
    if i >= d then
      if pal(i-d+1,i) then
      begin
        bad:=i;
        break;
      end;
    if i >= d+1 then
      if pal(i-d,i) then
      begin
        bad:=i;
        break;
      end;
  end;
  ok:=False;
  for i:=bad downto 1 do
  begin
    for c:=Chr(Ord(s[i])+1) to 'z' do
    begin
      s[i]:=c;
      h[i]:=h[i-1]*co+Ord(s[i]);
      hr[i]:=hr[i-1]+pw[i-1]*Ord(s[i]);
      if i >= d then
        if pal(i-d+1,i) then continue;
      if i >= d+1 then
        if pal(i-d,i) then continue;
      ok:=True;
      break;
    end;
    if ok then
    begin
      bad:=i;
      break;
    end;
  end;
  if not ok then writeln('Impossible') else
  begin
    for i:=bad+1 to n do
      for c:='a' to 'z' do
      begin
        s[i]:=c;
        h[i]:=h[i-1]*co+Ord(s[i]);
        hr[i]:=hr[i-1]+pw[i-1]*Ord(s[i]);
        if i >= d then
          if pal(i-d+1,i) then continue;
        if i >= d+1 then
          if pal(i-d,i) then continue;
        break;
      end;
    for i:=1 to n do write(s[i]);
    writeln;
  end;
end.