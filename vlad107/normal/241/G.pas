const
  c1=50000;
  c2=500;
  maxx=1000000;

var
  mm,ll,rr,j,n,i:longint;
  ok:boolean;
  x,p:array[0..500500]of longint;
  maxp:array[0..1000000]of longint;

  function cross(x1,r1,x2,r2:int64):boolean;
    begin
      if ((x1-x2)*(x1-x2)+(r1-r2)*(r1-r2)>=(r1+r2)*(r1+r2))then cross:=false else cross:=true;
    end;
    
  function bad:boolean;
    var
      i:longint;
      
    begin
      for i:=2 to n do
        if (cross(x[i],p[i],x[n+1],p[n+1]))then begin
          bad:=true;
          exit;
        end;
      bad:=false;
    end;
    
  procedure relax(i,j:longint);
    var
      ct:int64;
      
    begin
      ct:=int64(x[i]-x[j])*(x[i]-x[j]) div (4*p[i]);
      if (ct<p[j])then p[j]:=ct;
    end;

begin
  //assign(output,'output.txt');rewrite(output);
  n:=305;
  p[1]:=1000000;
  x[1]:=0;
  for i:=2 to n do begin
    x[i]:=x[i-1]+1;
    if (i=2)then p[i]:=1000 else p[i]:=p[i-1]-1;
    while (cross(x[i],p[i],x[i-1],p[i-1]))do inc(x[i]);
  end;
  x[n+1]:=1000000;
  p[n+1]:=1000000;
  for i:=2 to n do
    if (cross(x[i],p[i],x[i+1],p[i+1]))
      then begin
        writeln('fail');
      end;
  writeln(n+1);      
  for i:=1 to n+1 do writeln(x[i],' ',p[i]);
end.