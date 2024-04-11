{$r-,q-,s-,i-,o+}
var
  q,res,n,m,dx,i,j,x,y:longint;
  ch,c2:char;
  a:array[0..111,1..111]of char;
  w:array[#0..#255]of longint;

begin
  readln(n,m,dx);
  for i:=1 to n do readln(a[i]);
  fillchar(w,sizeof(w),$FF);
  for i:=1 to n do
    for j:=1 to m do
      if (a[i][j]<>'S')then w[a[i][j]]:=0;
  for ch:='A'to'Z'do begin
    c2:=chr(ord(ch)+32);
    for i:=1 to n do
      for j:=1 to m do
        if (a[i][j]=c2)then begin
          for x:=1 to n do
            for y:=1 to m do begin
              if (a[x][y]='S')and((x-i)*(x-i)+(y-j)*(y-j)<=dx*dx)then w[ch]:=0;
              if (a[x][y]='S')and(w[ch]<>0)then w[ch]:=1;
            end;
        end;           
  end;
  readln(q);
  res:=0;
  for i:=1 to q do begin
    read(ch);
    if (w[ch]<0)then begin
      writeln(-1);exit;
    end;
    res:=res+w[ch];
  end;
  writeln(res);
end.