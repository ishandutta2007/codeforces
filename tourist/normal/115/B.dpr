{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  n,m,i,j,ans,r,q,w: longint;
  a: array [0..155,0..155] of char;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n,m);
  fillchar(a,sizeof(a),'G');
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  r:=0;
  for i:=1 to n do
    for j:=1 to m do
      if a[i,j] = 'W' then r:=i;
  if r = 0 then
  begin
    writeln(0);
    halt;
  end;
  q:=1; ans:=-1;
  for i:=1 to r do
    if i and 1 = 1 then
    begin
      w:=q;
      for j:=1 to m do
        if (a[i,j] = 'W') or (a[i+1,j] = 'W') then
          if j > w then w:=j;
      ans:=ans+w-q+1;
      q:=w;
    end else
    begin
      w:=q;
      for j:=m downto 1 do
        if (a[i,j] = 'W') or (a[i+1,j] = 'W') then
          if j < w then w:=j;
      ans:=ans+q-w+1;
      q:=w;
    end;
  writeln(ans);
  close(input);
  close(output);
end.