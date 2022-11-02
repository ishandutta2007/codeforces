var
  pr,t,was:array[0..500500]of longint;
  kt,n,kg,i,j:longint;
  a:array[0..5001,0..5001]of char;
  ch:char;

  procedure solve;
    var
      j,i:longint;
    begin
      for i:=1 to kt div 2 do begin
        j:=t[i];t[i]:=t[kt-i+1];t[kt-i+1]:=j;
      end;
      for i:=1 to kt-3 do
        if (a[t[i+1]][t[kt]]='1')then begin
          writeln(t[i],' ',t[i+1],' ',t[kt]);
          halt(0);
        end;
      writeln(t[kt-2],' ',t[kt-1],' ',t[kt]);
      halt(0);
    end;

  procedure dfs(x:longint);
    var
      y:longint;
    begin
      was[x]:=1;
      for y:=1 to n do if (a[x][y]='1')then begin

        if (was[y]=0)then begin
          pr[y]:=x;
          dfs(y);
        end else
        if (was[y]=1)then begin
          kt:=0;
          while (x<>y)do begin
            inc(kt);
            t[kt]:=x;
            x:=pr[x];
          end;
          inc(kt);
          t[kt]:=x;
          solve;
        end;

      end;
      was[x]:=2;
    end;

begin
  readln(n);
  kg:=0;
  for i:=1 to n do begin
    for j:=1 to n do begin
      read(ch);
      a[i][j]:=ch;
    end;
    readln;
  end;

  for i:=1 to n do was[i]:=0;
  for i:=1 to n do
    if (was[i]=0)then dfs(i);
  writeln(-1);
end.