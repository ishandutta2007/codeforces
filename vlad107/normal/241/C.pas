{$r-,q-,s-,i-,o+}
var
  th,max,i,h1,h2,n:longint;
  ko,h,ss,ff,vv:array[0..500500]of longint;
  ch:char;

  function way(x1,y1,x2,y2,x3,y3:int64):int64;
    begin
      way:=(y2-y1)*(x3-x1)+(x1-x2)*(y3-y1);
    end;

  function cross(x1,y1,x2,y2,x3,y3,x4,y4:longint):boolean;
    var
      q1,q2,q3,q4:int64;
      
    begin
      q1:=way(x1,y1,x2,y2,x3,y3);
      q2:=way(x1,y1,x2,y2,x4,y4);
      q3:=way(x3,y3,x4,y4,x1,y1);
      q4:=way(x3,y3,x4,y4,x2,y2);
      if (q1*q2<=0)and(q3*q4<=0)
        then cross:=true
        else cross:=false;
    end;

  procedure solve;
    var
      sx,sy,ex,ey,sc,i,sxx,exx,syy,eyy,h3,j,k:longint;
      found:boolean;
      
    begin
      for i:=1 to n do begin
        if (i and 1=1)then h3:=100-h2 else h3:=h2;
        h3:=h3+100*i;
        sx:=0;ex:=100000;
        sy:=h1;ey:=h3;
        for j:=1 to n do ko[j]:=0;
        for j:=1 to i do begin
          th:=100*j;
          found:=false;
          for k:=1 to n do 
            if ((th-h[k])mod 200=0)then begin
              sxx:=ss[k];exx:=ff[k];
              if (cross(sx,sy,ex,ey,sxx,th,exx,th))
                then begin
                  inc(ko[k]);
                  found:=true;
                end;
            end;
          if (not found)then break;
        end;
        if (not found)then continue;
        sc:=0;
        for j:=1 to n do
          if (ko[j]>1)then begin
            found:=false;
            break;
          end else
          if (ko[j]=1)then inc(sc,vv[j]);
        if (not found)then continue;
        if (sc>max)then max:=sc;
      end;
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  readln(h1,h2,n);
  for i:=1 to n do begin
    readln(vv[i],ch,ch,ss[i],ff[i]);
    if (ch='T')then h[i]:=100 else h[i]:=0;
  end;
  max:=0;
  solve;
  for i:=1 to n do h[i]:=100-h[i];
  h1:=100-h1;
  h2:=100-h2;
  solve;
  writeln(max);
  close(output);close(input);
end.