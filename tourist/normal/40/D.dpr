{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
{$M 50000000}
type TLong = array [0..610] of longint;
var
  bns,a: array [0..1010] of TLong;
  b: TLong;
  s: ansistring;
  kb,ka,i,n,j: longint;
  ans: array [0..1010] of longint;

function mult(a:TLong;b:longint):TLong;
var
  i,v: longint;
begin
  v:=0;
  for i:=1 to a[0] do
  begin
    a[i]:=a[i]*b+v;
    v:=a[i] div 10;
    a[i]:=a[i]-v*10;
  end;
  while v > 0 do
  begin
    inc(a[0]);
    a[a[0]]:=v mod 10;
    v:=v div 10;
  end;
  mult:=a;
end;

function subtr(a,b:TLong):TLong;
var
  i,v: longint;
begin
  v:=0;
  for i:=1 to a[0] do
  begin
    a[i]:=a[i]-b[i]-v;
    if a[i] < 0 then
    begin
      inc(a[i],10);
      v:=1;
    end
    else v:=0;
  end;
  while (a[0] > 0) and (a[a[0]] = 0) do dec(a[0]);
  subtr:=a;
end;

procedure rec(v:longint;had2:boolean);
var
  i: longint;
  ok: boolean;
begin
  if a[v-1][0] > 333 then exit;
  if a[v-1][0] = b[0] then
  begin
    ok:=True;
    for i:=1 to b[0] do
      if b[i] <> a[v-1][i] then
      begin
        ok:=False;
        break;
      end;
    if ok then
    begin
      inc(ka);
      ans[ka]:=v-1;
      if ka > 1000 then ka:=1000;
    end;
  end;
  if not had2 then
  begin
    a[v]:=mult(a[v-2],12);
    rec(v+1,False);
  end;
  if (not had2) and (v and 1 = 0) then exit;
  a[v]:=subtr(mult(a[v-1],13),mult(a[v-2],12));
  rec(v+1,True);
end;

procedure rec2(v:longint;had2:boolean);
var
  i: longint;
  ok: boolean;
begin
  if v = n+1 then
  begin
    if a[v-1][0] = b[0] then
    begin
      ok:=True;
      for i:=1 to b[0] do
        if b[i] <> a[v-1][i] then
        begin
          ok:=False;
          break;
        end;
      if ok then exit;
    end;
    inc(kb);
    bns[kb]:=a[v-1];
    if kb > 1000 then kb:=1000;
    exit;
  end;
  if not had2 then
  begin
    a[v]:=mult(a[v-2],12);
    rec2(v+1,False);
  end;
  if (not had2) and (v and 1 = 0) then exit;
  a[v]:=subtr(mult(a[v-1],13),mult(a[v-2],12));
  rec2(v+1,True);
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(s);
  if s = '2' then
  begin
    writeln('YES');
    writeln(1);
    writeln(1);
    writeln(0);
    writeln;
    halt;
  end;
  fillchar(b,sizeof(b),0);
  b[0]:=length(s);
  for i:=1 to b[0] do b[i]:=Ord(s[b[0]-i+1])-48;
  ka:=0;
  fillchar(a,sizeof(a),0);
  a[1][0]:=1; a[1][1]:=2;
  a[2][0]:=2; a[2][1]:=3; a[2][2]:=1;
  rec(3,False);
  if ka = 0 then writeln('NO') else
  begin
    writeln('YES');
    writeln(ka);
    for i:=1 to ka-1 do write(ans[i],' ');
    writeln(ans[ka]);
    kb:=0;
    for i:=1 to ka do
    begin
      n:=ans[i];
      rec2(3,False);
    end;
    writeln(kb);
    for i:=1 to kb do
    begin
      for j:=bns[i][0] downto 1 do write(bns[i][j]);
      if i < kb then write(' ');
    end;
    writeln;
  end;
  close(input);
  close(output);
end.