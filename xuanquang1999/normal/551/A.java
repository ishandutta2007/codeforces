import java.util.*;

public class Main {
    public static class Student {
        int score, id;

        public Student(int score, int id) {
            this.score = score;
            this.id = id;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Student> stu = new ArrayList<>();

        for(int i = 0; i < n; ++i)
            stu.add(new Student(sc.nextInt(), i));

        Collections.sort(stu, Comparator.comparingInt(o -> o.score));

        int ans[] = new int[n];
        int j = n-1;
        for(int i = n-1; i >= 0; --i) {
            while (stu.get(j).score > stu.get(i).score) --j;
            ans[stu.get(i).id] = n-j;
        }

        for(int i = 0; i < n; ++i)
            System.out.printf("%d ", ans[i]);
    }
}