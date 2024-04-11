{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const dx: array [1..4] of longint = (0,1,0,-1);
      dy: array [1..4] of longint = (1,0,-1,0);
var
  x,y,i,j,xk,yk: longint;
  a: array [0..310,0..310] of longint;
  s: ansistring;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(s);
  fillchar(a,sizeof(a),0);
  x:=101; y:=101;
  a[x,y]:=1;
  for i:=2 to length(s)+1 do
  begin
    case s[i-1] of
      'U': inc(y);
      'L': dec(x);
      'R': inc(x);
      'D': dec(y);
    end;
    if a[x,y] <> 0 then
    begin
      writeln('BUG');
      halt;
    end;
    a[x,y]:=i;
    for j:=1 to 4 do
    begin
      xk:=x+dx[j];
      yk:=y+dy[j];
      if (a[xk,yk] <> 0) and (a[xk,yk] <> i-1) then
      begin
        writeln('BUG');
        halt;
      end;
    end;
  end;
  writeln('OK');
  close(input);
  close(output);
end.