{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const dx: array [1..4] of longint = (-1,0,1,0);
      dy: array [1..4] of longint = (0,1,0,-1);
      let: string = 'URDL';
var
  d,w: array [0..5555,0..5] of longint;
  a: array [0..5555,0..5555] of char;
  b: array [0..5555,0..5555] of longint;
  c,x,y: array [0..5555] of longint;
  n,m,i,j,nn,xx,yy,max,cnt,ii,ways: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  nn:=0;
  for i:=1 to n do
    for j:=1 to m do
      if a[i,j] <> '.' then
      begin
        inc(nn);
        b[i,j]:=nn;
        c[nn]:=Pos(a[i,j],let);
        x[nn]:=i;
        y[nn]:=j;
      end;
  for i:=1 to nn do
    for j:=1 to 4 do
    begin
      xx:=x[i]+dx[j];
      yy:=y[i]+dy[j];
      w[i,j]:=0;
      while (xx > 0) and (yy > 0) and (xx <= n) and (yy <= m) do
      begin
        if a[xx,yy] <> '.' then
        begin
          w[i,j]:=b[xx,yy];
          break;
        end;
        inc(xx,dx[j]);
        inc(yy,dy[j]);
      end;
    end;
  max:=-1; ways:=0;
  for ii:=1 to nn do
  begin
    for i:=1 to nn do
      for j:=1 to 4 do d[i,j]:=w[i,j];
    cnt:=0;
    i:=ii;
    while i <> 0 do
    begin
      d[d[i,1],3]:=d[i,3];
      d[d[i,3],1]:=d[i,1];
      d[d[i,2],4]:=d[i,4];
      d[d[i,4],2]:=d[i,2];
      i:=d[i,c[i]];
      inc(cnt);
    end;
    if cnt > max then
    begin
      max:=cnt;
      ways:=0;
    end;
    if cnt = max then inc(ways);
  end;
  writeln(max,' ',ways);
  close(input);
  close(output);
end.