{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const dx: array [1..8] of longint = (0,1,0,-1,1,1,-1,-1);
      dy: array [1..8] of longint = (1,0,-1,0,1,-1,1,-1);
var
  a: array [0..9,0..9] of longint;
  b: array [0..9,0..9] of boolean;
  xk,yk,x1,y1,x2,y2,x3,y3,x4,y4,d: longint;

procedure get(var x,y:longint);
var
  ch: char;
begin
  read(ch);
  while not (ch in ['a'..'h']) do read(ch);
  x:=Ord(ch)-96;
  read(y);
end;

procedure go(x,y,sx,sy:longint);
begin
  inc(x,sx); inc(y,sy);
  while (x > 0) and (y > 0) and (x < 9) and (y < 9) do
  begin
    b[x,y]:=True;
    if a[x,y] <> 0 then break;
    inc(x,sx); inc(y,sy);
  end;
end;

procedure go2(x,y,sx,sy:longint);
begin
  inc(x,sx); inc(y,sy);
  if (x > 0) and (y > 0) and (x < 9) and (y < 9) then
    b[x,y]:=True;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  get(x1,y1);
  get(x2,y2);
  get(x3,y3);
  get(x4,y4);
  fillchar(a,sizeof(a),0);
  a[x1,y1]:=1;
  a[x2,y2]:=2;
  a[x3,y3]:=3;
  fillchar(b,sizeof(b),False);
  for d:=1 to 4 do go(x1,y1,dx[d],dy[d]);
  for d:=1 to 4 do go(x2,y2,dx[d],dy[d]);
  for d:=1 to 8 do go2(x3,y3,dx[d],dy[d]);
  if not b[x4,y4] then writeln('OTHER') else
  begin
    for d:=1 to 8 do
    begin
      xk:=x4+dx[d];
      yk:=y4+dy[d];
      if (xk > 0) and (yk > 0) and (xk < 9) and (yk < 9) and (not b[xk,yk]) then
      begin
        writeln('OTHER');
        halt;
      end;
    end;
    writeln('CHECKMATE');
  end;
  close(input);
  close(output);
end.