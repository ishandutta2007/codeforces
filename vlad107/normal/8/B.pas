const
  abc='UDLR';
  hx:array[1..4]of longint=(0,0,-1,1);
  hy:array[1..4]of longint=(1,-1,0,0);
var
  cx,cy,q,x,y,i:longint;
  s:string;
  was:array[-111..111,-111..111]of longint;
begin
  fillchar(was,sizeof(was),false);
  readln(s);
  x:=0;y:=0;
  was[0][0]:=1;
  for i:=1 to length(s)do begin
    q:=pos(s[i],abc);
    inc(x,hx[q]);
    inc(y,hy[q]);
    if (was[x][y]>0)then begin
      writeln('BUG');
      exit;
    end;
    was[x][y]:=1;
    if (i<length(s))and(s[i+1]<>s[i])then 
      was[x+hx[q]][y+hy[q]]:=2;
  end;
  q:=0;
  for i:=1 to 4 do begin
    cx:=x+hx[i];
    cy:=y+hy[i];
    if (was[cx][cy]=1)then inc(q);
  end;
  if (q>1)then begin
    writeln('BUG');
    exit;
  end;
  for x:=-100 to 100 do for y:=-100 to 100 do begin 
    if (was[x][y]<>1)then continue;
    q:=0;
    for i:=1 to 4 do begin
      cx:=x+hx[i];
      cy:=y+hy[i];
      if (was[cx][cy]=1)then inc(q);
    end;
    if (q>2)then begin
      writeln('BUG');
      exit;
    end;
  end;
  writeln('OK');
end.