{$r-,q-,s-,i-,o+}
const
  hx:array[1..4]of longint=(0,1,-1,0);
  hy:array[1..4]of longint=(1,0,0,-1);

var
  a,b:array[0..555,0..555]of char;
  n,m,res,cr,cx,cy,q,qb,qe,i,j:longint;
  qx,qy:array[0..555555]of longint;
  used:array[0..555,0..555]of boolean;
  
  function check:boolean;
    var
      kh,i,j,q,x,y,cx,cy:longint;
      
    begin
      qb:=0;qe:=0;
      kh:=0;
      for i:=1 to n do 
        for j:=1 to m do used[i][j]:=false;
      for i:=1 to n do 
        for j:=1 to m do 
          if (not used[i][j])and(a[i][j]='#')then begin
            inc(kh);
            qb:=0;qe:=1;
            qx[1]:=i;
            qy[1]:=j;
            while (qb<qe)do begin
              inc(qb);
              x:=qx[qb];
              y:=qy[qb];
              for q:=1 to 4 do begin
                cx:=x+hx[q];
                cy:=y+hy[q];
                if (cx<1)or(cy<1)or(cx>n)or(cy>m)or(a[cx][cy]='.')or(used[cx][cy])then continue;
                used[cx][cy]:=true;
                inc(qe);
                qx[qe]:=cx;
                qy[qe]:=cy;
              end;
            end;
          end;
      check:=kh>1;
    end;

begin
  readln(n,m);
  for i:=1 to n do begin
    for j:=1 to m do read(a[i][j]);
    readln;
  end;
  for i:=1 to n do for j:=1 to m do b[i][j]:=a[i][j];
  res:=-1;
  for i:=1 to n do 
    for j:=1 to m do 
      if (a[i][j]='#')then begin
        a[i][j]:='.';
        if (check)then res:=1;
        a[i][j]:='#';
        cr:=0;
        for q:=1 to 4 do begin
          cx:=i+hx[q];
          cy:=j+hy[q];
          if (cx<1)or(cy<1)or(cx>n)or(cy>m)then continue;
          if (a[cx][cy]='#')then inc(cr);
          a[cx][cy]:='.';
        end;
        if (check)then begin
          if (res=-1)or(cr<res)then res:=cr;
        end;
        for q:=1 to 4 do begin
          cx:=i+hx[q];
          cy:=j+hy[q];
          if (cx<1)or(cy<1)or(cx>n)or(cy>m)then continue;
          a[cx][cy]:=b[cx][cy];
        end;
      end;
  writeln(res);      
end.