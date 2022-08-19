{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const let: string = 'NESW';
      dx: array [1..4] of longint = (-1,0,1,0);
      dy: array [1..4] of longint = (0,1,0,-1);
var
  n,m,i,j,k,q,ii,jj,x,y,xk,yk: longint;
  found,ok: boolean;
  ch: char;
  a: array [0..1010,0..1010] of char;
  ax,ay: array [0..1010,0..1010] of longint;
  c: array [0..111111] of char;
  d,dr: array [0..111111] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  fillchar(ax,sizeof(ax),0);
  fillchar(ay,sizeof(ay),0);
  for i:=1 to n do
    for j:=1 to m do
      if a[i,j] = '#' then ax[i,j]:=0
      else ax[i,j]:=ax[i,j-1]+1;
  for j:=1 to m do
    for i:=1 to n do
      if a[i,j] = '#' then ay[i,j]:=0
      else ay[i,j]:=ay[i-1,j]+1;
  readln(k);
  for i:=1 to k do
  begin
    readln(c[i],d[i]);
    dr[i]:=Pos(c[i],let);
  end;
  found:=False;
  for ch:='A' to 'Z' do
    for ii:=1 to n do
      for jj:=1 to m do
        if a[ii,jj] = ch then
        begin
          x:=ii; y:=jj;
          ok:=True;
          for i:=1 to k do
          begin
            xk:=x+dx[dr[i]]*d[i];
            yk:=y+dy[dr[i]]*d[i];
            if (xk < 1) or (yk < 1) or (xk > n) or (yk > m) then
            begin
              ok:=False;
              break;
            end;
            if dr[i] = 1 then q:=ay[x,y] else
            if dr[i] = 2 then q:=ax[xk,yk] else
            if dr[i] = 3 then q:=ay[xk,yk]
            else q:=ax[x,y];
            if q < d[i]+1 then
            begin
              ok:=False;
              break;
            end;
            x:=xk; y:=yk;
          end;
          if ok then
          begin
            found:=True;
            write(ch);
          end;
        end;
  if not found then write('no solution');
  writeln;
  close(input);
  close(output);
end.