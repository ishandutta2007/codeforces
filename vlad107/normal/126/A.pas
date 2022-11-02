var
  t1,t2,x1,x2,t,i,j,r1,r2:int64;

begin
  read(t1,t2,x1,x2,t);
  if (t1=t2)then begin
    writeln(x1,' ',x2);
    exit;
  end;
  if (t=t1)then begin
    writeln(x1,' ',0);
    exit;
  end;
  if (t=t2)then begin
    writeln(0,' ',x2);
    exit;
  end;
  i:=-1;
  r1:=0;r2:=0;
  while (i<x1)do begin
    i:=i+1;
    j:=(i*(t-t1))div(t2-t);
    if (t1*i+t2*j<t*(i+j))then j:=j+1;
    if (j>x2)then continue;
    if (r1=0)and(r2=0)then begin
      r1:=i;r2:=j;
    end else
    if ((t1*i+t2*j)*(r1+r2)<(t1*r1+t2*r2)*(i+j))then begin
      r1:=i;r2:=j;
    end else
    if ((t1*i+t2*j)*(r1+r2)=(t1*r1+t2*r2)*(i+j))and(i+j>r1+r2)then begin
      r1:=i;r2:=j;
    end;
  end;
  j:=-1;
  while (j<x2)do begin
    j:=j+1;
    i:=(j*(t2-t))div(t-t1);
    if (t1*i+t2*j<t*(i+j))then i:=i-1;
    if (i<x1)and(t1*(i+1)+t2*j>=t*((i+1)+j))then i:=i+1;
    if (t1*i+t2*j<t*(i+j))then continue;
    if (i>x1)then continue;
    if (i<0)then continue;
    if (r1=0)and(r2=0)then begin
      r1:=i;r2:=j;
    end else
    if ((t1*i+t2*j)*(r1+r2)<(t1*r1+t2*r2)*(i+j))then begin
      r1:=i;r2:=j;
    end else
    if ((t1*i+t2*j)*(r1+r2)=(t1*r1+t2*r2)*(i+j))and(i+j>r1+r2)then begin
      r1:=i;r2:=j;
    end;
  end;
  writeln(r1,' ',r2);
end.