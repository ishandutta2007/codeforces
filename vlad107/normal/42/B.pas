const
  hx:array[1..9] of longint=(1,1,1,0,0,-1,-1,-1,0);
  hy:array[1..9] of longint=(0,1,-1,1,-1,0,-1,1,0);

var
  s:string;
  x1,y1,x2,y2,bx,by,wx,wy,i,cx,cy,res:longint;
  w1,was:array[1..8,1..8] of boolean;

begin
  readln(s);
  x1:=ord(s[1])-96;
  y1:=ord(s[2])-48;
  x2:=ord(s[4])-96;
  y2:=ord(s[5])-48;
  wx:=ord(s[7])-96;
  wy:=ord(s[8])-48;
  bx:=ord(s[10])-96;
  by:=ord(s[11])-48;
  for i:=1 to 8 do begin
    cx:=wx+hx[i];
    cy:=wy+hy[i];
    if (cx<1)or (cy<1) or (cx>8) or (cy>8) then continue;
    was[cx][cy]:=true;
  end;

  for i:=x1+1 to 8 do begin
    if (i=wx) and (y1=wy)then break;
    w1[i][y1]:=true;
  end;
  for i:=y1-1 downto 1 do begin
    if (i=wy) and (x1=wx)then break;
    w1[x1][i]:=true;
  end;
  for i:=y1+1 to 8 do begin
    if (i=wy) and (x1=wx)then break;
    w1[x1][i]:=true;
  end;
  for i:=x1-1 downto 1 do begin
    if (i=wx) and (y1=wy)then break;
    w1[i][y1]:=true;
  end;

  
  for i:=x2+1 to 8 do begin
    if (i=wx) and (y2=wy)then break;
    w1[i][y2]:=true;
  end;
  for i:=y2-1 downto 1 do begin
    if (i=wy) and (x2=wx)then break;
    w1[x2][i]:=true;
  end;
  for i:=y2+1 to 8 do begin
    if (i=wy) and (x2=wx)then break;
    w1[x2][i]:=true;
  end;
  for i:=x2-1 downto 1 do begin
    if (i=wx) and (y2=wy)then break;
    w1[i][y2]:=true;
  end;

  
  res:=0;
  for i:=1 to 9 do begin
    cx:=bx+hx[i];
    cy:=by+hy[i];
    if (cx<1)or (cy<1) or (cx>8) or (cy>8)then inc(res) else
    if (was[cx][cy])then inc(res) else
    if (w1[cx][cy]) then inc(res) else
    if (w1[cx][cy]) then inc(res);
  end;
  if (res=9)
    then writeln('CHECKMATE')
    else writeln('OTHER');
end.