{$r-,q-,s-,i-,o+}
const
  maxt=111;

var
  max,qt,i,j,n,t,x,y:longint;
  u:array[-1111..1111,-1111..1111]of longint;
  found:boolean;

begin
  read(n,t);
  u[0][0]:=n;
  while (true)do begin
    found:=false;
    for i:=-maxt to maxt do 
      for j:=-maxt to maxt do 
        if (u[i][j]>=4)then begin
          qt:=u[i][j] div 4;
          inc(u[i+1][j],qt);
          inc(u[i][j+1],qt);
          inc(u[i-1][j],qt);
          inc(u[i][j-1],qt);
          u[i][j]:=u[i][j] mod 4;
          found:=true;
        end;
    if (not found)then break;
  end;
  for i:=1 to t do begin
    read(x,y);
    if (abs(x)+abs(y)>100)then begin
      writeln(0);
      continue;
    end else writeln(u[x][y]);
  end;
end.