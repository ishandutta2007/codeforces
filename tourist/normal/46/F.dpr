{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  id,key,n,m,k,i,j,x,y,z: longint;
  ch: char;
  dd: boolean;
  nam2: ansistring;
  nam: array [0..10010] of ansistring;
  open,openold: array [0..10010] of boolean;
  p,ss,ff,who,room,nk,room2: array [0..10010] of longint;

procedure wr;
begin
  writeln('NO');
  halt;
end;

function findset(x:longint):longint;
begin
  if x <> p[x] then p[x]:=findset(p[x]);
  findset:=p[x];
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,k);
  for i:=1 to m do read(ss[i],ff[i]);
  fillchar(who,sizeof(who),0);
  for i:=1 to k do
  begin
    read(ch);
    while not (ch in ['a'..'z','A'..'Z']) do read(ch);
    nam[i]:='';
    while ch in ['a'..'z','A'..'Z'] do
    begin
      nam[i]:=nam[i]+ch;
      read(ch);
    end;
    read(room[i],nk[i]);
    for j:=1 to nk[i] do
    begin
      read(key);
      who[key]:=i;
    end;
  end;
  fillchar(open,sizeof(open),False);
  for i:=1 to n do p[i]:=i;
  dd:=True;
  while dd do
  begin
    dd:=False;
    for i:=1 to m do
      if not open[i] then
      begin
        x:=findset(ss[i]);
        y:=findset(ff[i]);
        z:=findset(room[who[i]]);
        if (x = z) or (y = z) then
        begin
          open[i]:=True;
          dd:=True;
          if x <> y then p[x]:=y;
        end;
      end;
  end;
  for i:=1 to k do
  begin
    read(ch);
    while not (ch in ['a'..'z','A'..'Z']) do read(ch);
    nam2:='';
    while ch in ['a'..'z','A'..'Z'] do
    begin
      nam2:=nam2+ch;
      read(ch);
    end;
    id:=0;
    for j:=1 to k do
      if nam[j] = nam2 then
      begin
        id:=j;
        break;
      end;
    read(room2[i],nk[i]);
    x:=findset(room[id]);
    y:=findset(room2[i]);
    if x <> y then wr;
    for j:=1 to nk[i] do
    begin
      read(key);
      x:=findset(room[who[key]]);
      y:=findset(room2[i]);
      if x <> y then wr;
      who[key]:=i;
    end;
  end;
  for i:=1 to k do room[i]:=room2[i];
  openold:=open;
  fillchar(open,sizeof(open),False);
  for i:=1 to n do p[i]:=i;
  dd:=True;
  while dd do
  begin
    dd:=False;
    for i:=1 to m do
      if not open[i] then
      begin
        x:=findset(ss[i]);
        y:=findset(ff[i]);
        z:=findset(room[who[i]]);
        if (x = z) or (y = z) then
        begin
          open[i]:=True;
          dd:=True;
          if x <> y then p[x]:=y;
        end;
      end;
  end;
  for i:=1 to m do
    if openold[i] and not open[i] then wr;
  writeln('YES');
  close(input);
  close(output);
end.