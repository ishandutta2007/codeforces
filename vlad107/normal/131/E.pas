{$r-,q-,s-,i-,o+}
var
  minx,miny,maxx,maxy:array[1..5,-500500..500500]of longint;
  cr,n,m,i:longint;
  ans:array[0..10]of longint;
  x,y:array[0..500500]of longint;

  procedure add(q,t,x,y:longint);
    begin
      if (x<minx[q][t])or(x=minx[q][t])and(y<miny[q][t])then begin
        minx[q][t]:=x;
        miny[q][t]:=y;
      end;
      if (x>maxx[q][t])or(x=maxx[q][t])and(y>maxy[q][t])then begin
        maxx[q][t]:=x;
        maxy[q][t]:=y;
      end;
    end;

  procedure check(q,t,x,y:longint);
    begin
      if (minx[q][t]=maxx[q][t])and(miny[q][t]=maxy[q][t])then exit;
      if (x=minx[q][t])and(y=miny[q][t])then inc(cr) else
      if (x=maxx[q][t])and(y=maxy[q][t])then inc(cr) else
      inc(cr,2);
    end;

begin
  read(n,m);
  fillchar(minx,sizeof(minx),$F);
  fillchar(miny,sizeof(miny),$F);
  for i:=1 to m do begin
    read(x[i],y[i]);
    add(1,x[i],x[i],y[i]);
    add(2,y[i],x[i],y[i]);
    add(3,x[i]-y[i],x[i],y[i]);
    add(4,x[i]+y[i],x[i],y[i]);
  end;
  for i:=1 to m do begin
    cr:=0;
    check(1,x[i],x[i],y[i]);
    check(2,y[i],x[i],y[i]);
    check(3,x[i]-y[i],x[i],y[i]);
    check(4,x[i]+y[i],x[i],y[i]);
    inc(ans[cr]);
  end;
  for i:=0 to 8 do write(ans[i],' ');
  writeln;
end.