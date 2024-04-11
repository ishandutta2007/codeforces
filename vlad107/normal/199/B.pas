
var
  x,y,r:array[0..500]of longint;
  i,j,res:longint;
  
  function cross(x1,y1,r1,x2,y2,r2,r3:longint):boolean;
    begin
      if ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)>=(r1+r3)*(r1+r3))then begin
        cross:=false;
        exit;
      end;
      if (r1<=r2)and((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=(r1-r2)*(r1-r2))then begin
        cross:=false;
        exit;
      end;
      if (r1>=r3)and((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=(r1-r3)*(r1-r3))then begin
        cross:=false;
        exit;
      end;
      cross:=true;
    end;

begin
  read(x[1],y[1],r[1],r[2]);
  x[2]:=x[1];y[2]:=y[1];
  read(x[3],y[3],r[3],r[4]);
  x[4]:=x[3];y[4]:=y[3];
  res:=0;
  if (not cross(x[3],y[3],r[3],x[1],y[1],r[1],r[2]))then inc(res);
  if (not cross(x[4],y[4],r[4],x[1],y[1],r[1],r[2]))then inc(res);
  if (not cross(x[1],y[1],r[1],x[3],y[3],r[3],r[4]))then inc(res);
  if (not cross(x[2],y[2],r[2],x[3],y[3],r[3],r[4]))then inc(res);
  writeln(res);
end.