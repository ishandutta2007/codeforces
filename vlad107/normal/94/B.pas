var
  n,i,j,k,x,y:longint;
  g:array[0..10,0..10]of boolean;

begin
  read(n);
  fillchar(g,sizeof(g),false);
  for i:=1 to n do begin
    read(x,y);
    g[x][y]:=true;
    g[y][x]:=true;
  end;
  for i:=1 to 5 do 
    for j:=i+1 to 5 do 
      for k:=j+1 to 5 do 
        if (g[i][j]=g[j][k])and(g[j][k]=g[i][k])
          then begin
            writeln('WIN');
            exit;
          end;
  writeln('FAIL');          
end.