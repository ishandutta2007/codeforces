var
  res,i,j,n,k,q,t:longint;
  f:array[1..101,-101..101,-1..1,0..51]of boolean;
  s:ansistring;

begin
  readln(s);
  readln(k);
  n:=length(s);

  fillchar(f,sizeof(f),false);
  f[1][0][1][0]:=true;
  for i:=1 to n do 
    for j:=-100 to 100 do 
      for q:=-1 to 1 do if (q<>0)then
        for t:=0 to k do 
          if (f[i][j][q][t])then begin
            if (s[i]='F')
              then begin
                f[i+1][j+q][q][t]:=true;
                if (t<k)then f[i+1][j][-q][t+1]:=true;
              end else begin
                f[i+1][j][-q][t]:=true;
                if (t<k)then f[i+1][j+q][q][t+1]:=true;
              end;
          end;
  res:=0;
  for j:=-100 to 100 do 
    for q:=-1 to 1 do
      for t:=0 to k do  
        if ((k-t)and 1=0)and(q<>0)and(f[n+1][j][q][t])and(abs(j)>res)then res:=abs(j);
  writeln(res);
end.