var
  x,y,dst:array[0..500]of longint;
  t:array[0..2,0..10]of longint;
  used:array[0..8]of boolean;
  i5,i6,i7,i8,kt,i,i1,i2,i3,i4,j:longint;
 
  function way(x1,y1,x2,y2,x3,y3:longint):longint;
    begin
      way:=(y2-y1)*(x3-x1)+(x1-x2)*(y3-y1);
    end;
    
  function dist(x1,y1,x2,y2:longint):longint;
    begin
      dist:=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    end;

  function ok(q:longint):boolean;
    var
      o,i,j:longint;
      
    begin
      ok:=false;
      for i:=1 to 4 do begin
        j:=i mod 4+1;
        o:=j mod 4+1;
        if (way(x[t[q][i]],y[t[q][i]],
                x[t[q][j]],y[t[q][j]],
                x[t[q][o]],y[t[q][o]])<=0)then exit;
        if (dist(x[t[q][i]],y[t[q][i]],x[t[q][j]],y[t[q][j]])+
            dist(x[t[q][j]],y[t[q][j]],x[t[q][o]],y[t[q][o]])<>
            dist(x[t[q][i]],y[t[q][i]],x[t[q][o]],y[t[q][o]]))then exit;
      end;
      ok:=true;
    end;
    
begin
  for i:=1 to 8 do read(x[i],y[i]);
  for i1:=1 to 8 do 
    for i2:=1 to 8 do 
      for i3:=1 to 8 do
        for i4:=1 to 8 do 
          for i5:=1 to 8 do
            for i6:=1 to 8 do 
              for i7:=1 to 8 do 
                for i8:=1 to 8 do begin
                  fillchar(used,sizeof(used),false);
                  used[i1]:=true;t[1][1]:=i1;
                  used[i2]:=true;t[1][2]:=i2;
                  used[i3]:=true;t[1][3]:=i3;
                  used[i4]:=true;t[1][4]:=i4;
                  
                  used[i5]:=true;t[2][1]:=i5;
                  used[i6]:=true;t[2][2]:=i6;
                  used[i7]:=true;t[2][3]:=i7;
                  used[i8]:=true;t[2][4]:=i8;
                  kt:=0;
                  for i:=1 to 8 do 
                    if (not used[i])then inc(kt);
                  if (kt<>0)then continue;
                  if (not ok(1))or(not ok(2))then continue;
                  for i:=1 to 4 do begin
                    j:=i mod 4+1;
                    dst[i]:=dist(x[t[1][i]],y[t[1][i]],x[t[1][j]],y[t[1][j]]);
                    if (i>1)and(dst[i]<>dst[i-1])then begin
                      dst[1]:=-1;
                      break;
                    end;
                  end;
                  if (dst[1]=-1)then continue;
                  writeln('YES');
                  for i:=1 to 2 do begin
                    for j:=1 to 4 do write(t[i][j],' ');
                    writeln;
                  end;
                  exit;
                end;
  writeln('NO');        
end.