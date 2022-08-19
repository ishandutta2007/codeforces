{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const n = 40000; m = 31;
var
  a,b,t,i,z,w,j,mp,u: longint;
  win: array [0..n+10,0..m+10] of shortint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(a,b,t);
  fillchar(win,sizeof(win),0);
  for i:=n downto 2 do
  begin
    z:=i; w:=(t-1) div i;
    mp:=0;
    for j:=2 to m do
      if z > w then
      begin
        mp:=j;
        break;
      end
      else z:=z*i;
    for j:=m downto 2 do
      if j >= mp then win[i,j]:=1 else
      if (win[i+1,j] = 1) and (win[i,j+1] = 1) then win[i,j]:=-1
      else win[i,j]:=1;
  end;
  if t <= n then u:=t else
  if (t-n) and 1 = 1 then u:=n-1
  else u:=n;
  for i:=u to n do win[i,1]:=1;
  for i:=u-1 downto 2 do
    if (win[i+1,1] = 1) and (win[i,2] = 1) then win[i,1]:=-1
    else win[i,1]:=1;
  win[1,m]:=0;
  for j:=m-1 downto 1 do
  begin
    win[1,j]:=-1;
    if -win[1,j+1] > win[1,j] then win[1,j]:=-win[1,j+1];
    if -win[2,j] > win[1,j] then win[1,j]:=-win[2,j];
  end;
  if win[a,b] = 1 then writeln('Masha') else
  if win[a,b] = -1 then writeln('Stas')
  else writeln('Missing');
  close(input);
  close(output);
end.