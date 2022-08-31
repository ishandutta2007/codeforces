{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const let: string = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ';
var
  s: array [0..9] of ansistring;
  iii,jjj,ii,jj,ka,i,j: longint;
  need: char;
  ok: boolean;
  a1: array [0..10010] of char;
  a2: array [0..10010] of longint;

procedure add(ch:char;i:longint);
begin
  inc(ka);
  a1[ka]:=ch;
  a2[ka]:=i;
end;

procedure right(i:longint);
var
  j: longint;
  tmp: char;
begin
  add('R',i);
  tmp:=s[i,6];
  for j:=6 downto 2 do s[i,j]:=s[i,j-1];
  s[i,1]:=tmp;
end;

procedure left(i:longint);
var
  j: longint;
  tmp: char;
begin
  add('L',i);
  tmp:=s[i,1];
  for j:=1 to 5 do s[i,j]:=s[i,j+1];
  s[i,6]:=tmp;
end;

procedure up(j:longint);
var
  i: longint;
  tmp: char;
begin
  add('U',j);
  tmp:=s[1,j];
  for i:=1 to 5 do s[i,j]:=s[i+1,j];
  s[6,j]:=tmp;
end;

procedure down(j:longint);
var
  i: longint;
  tmp: char;
begin
  add('D',j);
  tmp:=s[6,j];
  for i:=6 downto 2 do s[i,j]:=s[i-1,j];
  s[1,j]:=tmp;
end;

procedure change(i1,j1,i2,j2:longint);
begin
  if i1 = i2 then
  begin
    right(i1);
    up(j1);
    right(i1);
    down(j1);
    right(i1);
    up(j1);
    right(i1);
    down(j1);
    right(i1);
    up(j1);
    right(i1);
    right(i1);
    down(j1);
  end else
  begin
    down(j1);
    left(i1);
    down(j1);
    right(i1);
    down(j1);
    left(i1);
    down(j1);
    right(i1);
    down(j1);
    left(i1);
    down(j1);
    down(j1);
    right(i1);
  end;
end;

begin
  for i:=1 to 6 do readln(s[i]);
  ka:=0;
  for i:=1 to 6 do
    for j:=1 to 6 do
    begin
      need:=let[(i-1)*6+j];
      ok:=False;
      for iii:=1 to 6 do
      begin
        for jjj:=1 to 6 do
          if s[iii,jjj] = need then
          begin
            ii:=iii; jj:=jjj;
            while jj > j do
            begin
              change(ii,jj-1,ii,jj);
              dec(jj);
            end;
            while jj < j do
            begin
              change(ii,jj,ii,jj+1);
              inc(jj);
            end;
            while ii > i do
            begin
              change(ii-1,jj,ii,jj);
              dec(ii);
            end;
            ok:=True;
            break;
          end;
        if ok then break;
      end;
    end;
  writeln(ka);
  for i:=1 to ka do writeln(a1[i],a2[i]);
end.