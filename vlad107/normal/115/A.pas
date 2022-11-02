var
  cr,res,n,i,x:longint;
  g:array[0..2222,0..2222]of boolean;
  used:array[0..2222]of boolean;
  pred:array[0..2222]of longint;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do begin
    read(x);
    pred[i]:=x;
  end;
  res:=0;
  for i:=1 to n do begin
    x:=i;
    cr:=0;
    while (pred[x]<>-1)do begin
      x:=pred[x];g[i][x]:=true;g[x][i]:=true;inc(cr);
    end;
    if (cr>res)then res:=cr;
  end;
  writeln(1+res);
  close(output);close(input);
end.