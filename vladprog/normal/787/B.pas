var
  m,i,j,k,v:longint;
  yes:boolean;
  plus:array[1..10000]of boolean;
  minus:array[1..10000]of boolean;

begin
  read(m);
  read(m);
  for i:=1 to m do
    begin
      fillchar(plus,sizeof(plus),0);
      fillchar(minus,sizeof(minus),0);
      yes:=true;
      read(k);
      for j:=1 to k do
        begin
          read(v);
          if v>0
            then
              begin
                plus[v]:=true;
                if minus[v] then
                  yes:=false;
              end
            else
              begin
                minus[-v]:=true;
                if plus[-v] then
                  yes:=false;
              end
        end;
      if yes then
        begin
          writeln('YES');
          halt
        end
    end;
  writeln('NO')
end.