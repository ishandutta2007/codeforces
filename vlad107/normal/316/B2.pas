var
  n,x,i,j,lm:longint;
  last,p:array[0..500500]of boolean;
  next:array[0..500500]of longint;

begin
  read(n,x);
  fillchar(last,sizeof(last),true);
  for i:=1 to n do begin
    read(next[i]);
    last[next[i]]:=false;
  end;
  p[0]:=true;
  for i:=1 to n do 
    if (last[i])then begin
      j:=i;
      while (j<>0)and(j<>x)do j:=next[j];
      if (j=x)then continue;
      j:=i;lm:=0;
      while (j<>0)do begin inc(lm);j:=next[j];end;
      for j:=n downto lm do p[j]:=p[j] or p[j-lm];
    end;
  lm:=0;
  while (x<>0)do begin inc(lm);x:=next[x];end;
  for i:=0 to n do if (p[i])then writeln(i+lm);
end.