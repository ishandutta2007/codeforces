const
  hx:array[1..4]of longint=(1,0,-1,0);
  hy:array[1..4]of longint=(0,1,0,-1);
var
  cx,cy,q,n,m,i,j,res:longint;
  a:array[0..1111,0..111]of char;

begin
  readln(n,m);
  for i:=1 to n do begin
    for j:=1 to m do read(a[i][j]); 
    readln;
  end;
  res:=0;
  for i:=1 to n do
    for j:=1 to m do begin
      if (a[i][j]<>'P')then continue;
      for q:=1 to 4 do begin
        cx:=i+hx[q];cy:=j+hy[q];
        if (a[cx][cy]='W')then begin
          inc(res);a[cx][cy]:='.';break;
        end;
      end;
    end; 
  writeln(res);
end.