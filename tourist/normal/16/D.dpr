{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  la,lb,lc,tt,qq,ans,hh,mm: longint;
  ch: char;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(tt);
  la:=0; lb:=0; lc:=0;
  ans:=1;
  for qq:=1 to tt do
  begin
    hh:=0; mm:=0;
    read(ch);
    while not (ch in ['0'..'9']) do read(ch);
    while ch in ['0'..'9'] do
    begin
      hh:=hh*10+Ord(ch)-48;
      read(ch);
    end;
    while not (ch in ['0'..'9']) do read(ch);
    while ch in ['0'..'9'] do
    begin
      mm:=mm*10+Ord(ch)-48;
      read(ch);
    end;
    while not (ch in ['a','p']) do read(ch);
    readln;
    if hh = 12 then hh:=0;
    if ch = 'p' then hh:=hh+12;
    if (hh < la) or (hh = la) and (mm < lb) or (hh = la) and (mm = lb) and (lc = 10) then
    begin
      inc(ans);
      lc:=1;
    end else
    if (hh = la) and (mm = lb) then inc(lc)
    else lc:=1;
    la:=hh;
    lb:=mm;
  end;
  writeln(ans);
  close(input);
  close(output);
end.