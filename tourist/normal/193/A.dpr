{$R-,S-,Q-,I-,O+}
const dx: array [1..4] of longint = (0,1,0,-1);
      dy: array [1..4] of longint = (1,0,-1,0);
var
  xk,yk,n,m,i,j,cnt,ii,jj,e: longint;
  ch: char;
  a: array [0..55,0..55] of char;
  was: array [0..55,0..55] of boolean;
  x,y: array [0..5555] of longint;
begin
  read(n,m);
  for i:=1 to n do
    for j:=1 to m do
    begin
      read(ch);
      while not (ch in ['.','#']) do read(ch);
      a[i,j]:=ch;
    end;
  cnt:=0;
  for i:=1 to n do
    for j:=1 to m do
      if a[i,j] = '#' then inc(cnt);
  if cnt < 3 then
  begin
    writeln(-1);
    halt;
  end;
  for ii:=1 to n do
    for jj:=1 to m do
      if a[ii,jj] = '#' then
      begin
        a[ii,jj]:='.';
        fillchar(was,sizeof(was),False);
        x[1]:=0; y[1]:=0;
        for i:=1 to n do
        begin
          for j:=1 to m do
            if a[i,j] = '#' then
            begin
              x[1]:=i;
              y[1]:=j;
              break;
            end;
          if x[1] > 0 then break;
        end;
        i:=1; e:=1;
        was[x[1],y[1]]:=True;
        while i <= e do
        begin
          for j:=1 to 4 do
          begin
            xk:=x[i]+dx[j];
            yk:=y[i]+dy[j];
            if (xk > 0) and (yk > 0) and (xk <= n) and (yk <= m) then
              if (a[xk,yk] = '#') and (not was[xk,yk]) then
              begin
                inc(e);
                x[e]:=xk;
                y[e]:=yk;
                was[xk,yk]:=True;
              end;
          end;
          inc(i);
        end;
        if e < cnt-1 then
        begin
          writeln(1);
          halt;
        end;
        a[ii,jj]:='#';
      end;
  writeln(2);
end.