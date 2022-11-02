var
  x,y:array[0..5555]of longint;
  ans,n,i,j:longint;
  used:array[-2111..2111,-2111..2111]of boolean;

begin
  read(n);
  fillchar(used,sizeof(used),false);
  for i:=1 to n do begin
    read(x[i],y[i]);
    used[x[i]][y[i]]:=true;
  end;
  ans:=0;
  for i:=1 to n do 
    for j:=i+1 to n do 
      if (abs((x[i]+x[j])mod 2)+abs((y[i]+y[j])mod 2)=0)and(used[(x[i]+x[j])div 2][(y[i]+y[j])div 2])
        then inc(ans);
  writeln(ans);
end.