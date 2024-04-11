{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const dx: array [1..9] of longint = (0,1,0,-1,1,1,-1,-1,0);
      dy: array [1..9] of longint = (1,0,-1,0,1,-1,1,-1,0);
var
  can,ncan: array [0..9,0..9] of boolean;
  a: array [0..9,0..9] of char;
  i,j,it,xk,yk,q: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  for i:=1 to 8 do
  begin
    for j:=1 to 8 do read(a[i,j]);
    readln;
  end;
  fillchar(can,sizeof(can),False);
  for i:=1 to 8 do
    for j:=1 to 8 do
      if a[i,j] = 'M' then can[i,j]:=True;
  for it:=1 to 1000 do
  begin
    for i:=1 to 8 do
      for j:=1 to 8 do
        if can[i,j] and (a[i,j] = 'A') then
        begin
          writeln('WIN');
          halt;
        end;
    fillchar(ncan,sizeof(ncan),False);
    for i:=1 to 8 do
      for j:=1 to 8 do
        if can[i,j] then
          for q:=1 to 9 do
          begin
            xk:=i+dx[q];
            yk:=j+dy[q];
            if (xk > 0) and (yk > 0) and (xk < 9) and (yk < 9) then ncan[xk,yk]:=True;
          end;
    for i:=1 to 8 do
      for j:=1 to 8 do
        if a[i,j] = 'S' then
        begin
          xk:=i+it-1;
          yk:=j;
          if (xk > 0) and (yk > 0) and (xk < 9) and (yk < 9) then ncan[xk,yk]:=False;
          xk:=i+it;
          yk:=j;
          if (xk > 0) and (yk > 0) and (xk < 9) and (yk < 9) then ncan[xk,yk]:=False;
        end;
    can:=ncan;
  end;
  writeln('LOSE');
  close(input);
  close(output);
end.