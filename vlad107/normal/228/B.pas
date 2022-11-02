var
  c1,c2,max,cr,ax,ay,x,y,i,j,n1,n2,m1,m2:longint;
  ch:char;
  a,b:array[-55..55,-55..55]of longint;

begin
  readln(n1,m1);
  for i:=1 to n1 do begin
    for j:=1 to m1 do begin
      read(ch);
      a[i][j]:=ord(ch)-48;
    end;
    readln;
  end;
  readln(n2,m2);
  for i:=1 to n2 do begin
    for j:=1 to m2 do begin
      read(ch);
      b[i][j]:=ord(ch)-48;
    end;
    readln;
  end;
  max:=-1;
  for x:=-50 to 50 do  
    for y:=-50 to 50 do begin
      cr:=0;
      for i:=1 to n1 do 
        for j:=1 to m1 do begin
          c1:=a[i][j];
          if (i+x<1)or(i+x>n2)then c2:=0 else
          if (j+y<1)or(j+y>m2)then c2:=0 else
          c2:=b[i+x][j+y];
          cr:=cr+c1*c2;
        end;
      if (cr>max)then begin
        max:=cr;
        ax:=x;ay:=y;
      end;;
    end;
  writeln(ax,' ',ay);
end.