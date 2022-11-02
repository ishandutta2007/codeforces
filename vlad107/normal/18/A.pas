var
  a,b,c,i,j,k,hxi,hyi,hxj,hyj,hxk,hyk,cxi,cyi,cxj,cyj,cxk,cyk:longint;
  x,y:array[1..10]of longint;
  almost:boolean;
  function dist(x1,y1,x2,y2:longint):longint;
    begin
      dist:=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    end;
begin
  for i:=1 to 3 do read(x[i],y[i]);
  almost:=false;
  for i:=1 to 3 do
    for j:=1 to 3 do if (i<>j)then
      for k:=1 to 3 do if (k<>i)and(k<>j)then begin
        a:=dist(x[i],y[i],x[j],y[j]);
        b:=dist(x[j],y[j],x[k],y[k]);
        c:=dist(x[i],y[i],x[k],y[k]);
        if (a+b=c)and(a>0)and(b>0)then begin
          writeln('RIGHT');
          exit;
        end;
        for hxi:=-1 to 1 do
          for hyi:=-1 to 1 do
            for hxj:=-1 to 1 do
              for hyj:=-1 to 1 do
                for hxk:=-1 to 1 do
                  for hyk:=-1 to 1 do
                    if (abs(hxi)+abs(hyi)+abs(hxj)+abs(hyj)+abs(hxk)+abs(hyk)=1)then begin
                      cxi:=x[i]+hxi;cyi:=y[i]+hyi;
                      cxj:=x[j]+hxj;cyj:=y[j]+hyj;
                      cxk:=x[k]+hxk;cyk:=y[k]+hyk;
                      a:=dist(cxi,cyi,cxj,cyj);
                      b:=dist(cxj,cyj,cxk,cyk);
                      c:=dist(cxi,cyi,cxk,cyk);
                      if (a+b=c)and(a>0)and(b>0)
                        then almost:=true;
                    end;
      end;
  if (almost)
    then writeln('ALMOST')
    else writeln('NEITHER');
end.