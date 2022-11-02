{$r-,q-,s-,i-,o+}
const
  tt1:array[1..13]of char=('2','3','4','5','6','7','8','9','T','J','Q','K','A');
  tt2:array[1..4]of char=('C','D','H','S');
var
  s:string;
  q,kr,n,m,qqq,i,j,kt:longint;
  b,a:array[1..20,1..20]of string;
  was:array[#0..#255]of longint;
  used:array[0..100]of boolean;
  t:array[0..100]of string;
  rx,ry:array[0..5]of longint;
  function ok(x,y:longint):boolean;
    var
      good:boolean;
      i,j:longint;
    begin
      good:=true;
      for i:=1 to 3 do
        for j:=1 to 3 do
          if (b[x-i+1][y-j+1][2]<>b[x][y][2])then good:=false;
      if (good)then begin
        ok:=true;
        exit;
      end;
      ok:=true;
      inc(qqq);
      for i:=1 to 3 do
        for j:=1 to 3 do
          if (was[b[x-i+1][y-j+1][1]]=qqq)then begin
            ok:=false;
            exit;
          end else was[b[x-i+1,y-j+1][1]]:=qqq;
    end;
  procedure rec(qt:longint);
    var
      i,j,x,y:longint;
    begin
      if (qt=kr)then begin
        for i:=3 to n do
          for j:=3 to m do
            if (ok(i,j))then
              for x:=i-3+1 to n-3+1 do
                for y:=1 to m-3+1 do begin
                  if (x<=i)and(y<=j)then continue;

                  if (ok(x+2,y+2))then begin
                    writeln('Solution exists.');
                    case (kr)of
                      0:writeln('There are no jokers.');
                      1:writeln('Replace ',a[rx[1]][ry[1]],' with ',b[rx[1]][ry[1]],'.');
                      2:begin
                          write('Replace J1 with ');
                          if (a[rx[1]][ry[1]]='J1')
                            then writeln(b[rx[1]][ry[1]],' and J2 with ',b[rx[2]][ry[2]],'.')
                            else writeln(b[rx[2]][ry[2]],' and J2 with ',b[rx[1]][ry[1]],'.');
                        end;
                    end;
                    writeln('Put the first square to (',i-3+1,', ',j-3+1,').');
                    writeln('Put the second square to (',x,', ',y,').');
                    halt;
                  end;
                end;
        exit;
      end;
      inc(qt);
      for i:=1 to 52 do
        if (not used[i])then begin
          b[rx[qt]][ry[qt]]:=t[i];
          used[i]:=true;
          rec(qt);
          used[i]:=false;
        end;
    end;
begin
  qqq:=0;
  readln(n,m);
  for i:=1 to n do begin
    readln(s);
    for j:=1 to m do
      a[i][j]:=s[1+3*(j-1)]+s[2+3*(j-1)];
  end;
  for i:=1 to 13 do
    for j:=1 to 4 do begin
      inc(kt);
      t[kt]:=tt1[i]+tt2[j];
    end;
  fillchar(used,sizeof(used),false);
  for i:=1 to n do
    for j:=1 to m do
      for q:=1 to kt do
        if (a[i][j]=t[q])then used[q]:=true;
  kr:=0;
  for i:=1 to n do
    for j:=1 to m do
      if (a[i][j]='J1')or(a[i][j]='J2')then begin
        inc(kr);
        rx[kr]:=i;
        ry[kr]:=j;
      end;
  for i:=1 to n do for j:=1 to m do b[i][j]:=a[i][j];
  rec(0);
  writeln('No solution.');
end.